package com.example.esp32bluetoothconfig;

import android.app.Activity;
import android.bluetooth.BluetoothAdapter;
import android.bluetooth.BluetoothDevice;
import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.content.IntentFilter;
import android.os.Bundle;
import android.support.v4.app.Fragment;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.AbsListView;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.CompoundButton;
import android.widget.ListAdapter;
import android.widget.TextView;
import android.widget.Toast;
import android.widget.ToggleButton;

import java.util.ArrayList;
import java.util.Set;

public class DeviceListFragment extends Fragment implements AbsListView.OnItemClickListener{

    private static BluetoothHelper BTHelper;
    //private ArrayList <DeviceItem>deviceItemList;

    private OnFragmentInteractionListener mListener;
    //private static BluetoothAdapter bTAdapter;

    private static Context context;

    /**
     * The fragment's ListView/GridView.
     */
    private AbsListView mListView;

    /**
     * The Adapter which will be used to populate the ListView/GridView with
     * Views.
     */
    private static ArrayAdapter<DeviceItem> mAdapter;


    // TODO: Rename and change types of parameters
    public static DeviceListFragment newInstance(BluetoothHelper btHelper, Context ctx) {
        BTHelper = btHelper;
        context = ctx;
        DeviceListFragment fragment = new DeviceListFragment();
        //bTAdapter = btHelper.BTAdapter;
        return fragment;
    }

    /**
     * Mandatory empty constructor for the fragment manager to instantiate the
     * fragment (e.g. upon screen orientation changes).
     */
    public DeviceListFragment() {
    }

    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);


        Log.d("DEVICELIST", "Super called for DeviceListFragment onCreate\n");
        //Obtenemos los dispositivos apareados con este dispositivo
        BTHelper.getPairedDevices();

        //Inicializamos el adaptador que se mostrara en pantalla con la lista de dispositivos
        mAdapter = new DeviceListAdapter(getActivity(), BTHelper.getDeviceItemList(), BTHelper.getAdapter());
        Log.d("DEVICELIST", "Adapter created\n");
        //Configuramos la lista que se llenara al ir detectando dispositivos disponibles
        BTHelper.configureBroadcastReceiver(mAdapter);
    }

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {
        View view = inflater.inflate(R.layout.fragment_deviceitem_list, container, false);
        ToggleButton scan = (ToggleButton) view.findViewById(R.id.scan);
        // Set the adapter
        mListView = (AbsListView) view.findViewById(android.R.id.list);
        ((AdapterView<ListAdapter>) mListView).setAdapter(mAdapter);

        // Set OnItemClickListener so we can be notified on item clicks
        mListView.setOnItemClickListener(this);

        scan.setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener() {
            public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                IntentFilter filter = new IntentFilter(BluetoothDevice.ACTION_FOUND);
                if (isChecked) {
                    mAdapter.clear();
                    getActivity().registerReceiver(BTHelper.getBroadcastReceiver(), filter);
                    BTHelper.getAdapter().startDiscovery();
                } else {
                    getActivity().unregisterReceiver(BTHelper.getBroadcastReceiver());
                    BTHelper.getAdapter().cancelDiscovery();
                }
            }
        });

        return view;
    }

    /*@Override
    public void onAttach(Activity activity) {
        super.onAttach(activity);
        try {
            mListener = (OnFragmentInteractionListener) activity;
        } catch (ClassCastException e) {
            throw new ClassCastException(activity.toString()
                    + " must implement OnFragmentInteractionListener");
        }
    }*/

    @Override
    public void onDetach() {
        super.onDetach();
        mListener = null;
    }

    @Override
    public void onItemClick(AdapterView<?> parent, View view, int position, long id) {
        //Cancelamos la busqueda de dispositivos
        try {
            getActivity().unregisterReceiver(BTHelper.getBroadcastReceiver());
        }
        catch (Exception e){
            //Si se selecciona un elemento de los apareados y nunca se inicio la busqueda de dispositivos
        }
        BTHelper.getAdapter().cancelDiscovery();
        Log.d("DEVICELIST", "onItemClick position: " + position +
                " id: " + id + " name: " + BTHelper.getDeviceItemList().get(position).getDeviceName() + "\n");
        if (null != mListener) {
            // Notify the active callbacks interface (the activity, if the
            // fragment is attached to one) that an item has been selected.
            mListener.onFragmentInteraction(BTHelper.getDeviceItemList().get(position).getDeviceName());
        }
        //Le pasamos el contexto para que finalice la actividad en caso de que pueda conectarse
        BTHelper.connectToDevice(BTHelper.getDeviceItemList().get(position), context);
    }

    /**
     * The default content for this Fragment has a TextView that is shown when
     * the list is empty. If you would like to change the text, call this method
     * to supply the text it should use.
     */
    public void setEmptyText(CharSequence emptyText) {
        View emptyView = mListView.getEmptyView();

        if (emptyView instanceof TextView) {
            ((TextView) emptyView).setText(emptyText);
        }
    }

    /**
     * This interface must be implemented by activities that contain this
     * fragment to allow an interaction in this fragment to be communicated
     * to the activity and potentially other fragments contained in that
     * activity.
     * <p/>
     * See the Android Training lesson <a href=
     * "http://developer.android.com/training/basics/fragments/communicating.html"
     * >Communicating with Other Fragments</a> for more information.
     */
    public interface OnFragmentInteractionListener {
        // TODO: Update argument type and name
        public void onFragmentInteraction(String id);
    }
}