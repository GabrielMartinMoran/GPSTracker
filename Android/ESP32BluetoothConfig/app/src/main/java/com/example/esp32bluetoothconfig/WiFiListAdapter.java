package com.example.esp32bluetoothconfig;

import android.app.Activity;
import android.bluetooth.BluetoothAdapter;
import android.content.Context;
import android.content.Intent;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.ListView;
import android.widget.RelativeLayout;
import android.widget.TextView;
import android.widget.Toast;

import java.util.List;

/**
 * Created by Matt on 5/12/2015.
 */
public class WiFiListAdapter extends ArrayAdapter<String>{

    private Context context;
    private List itemsList;

    public WiFiListAdapter(Context context, List items) {
        super(context, android.R.layout.simple_list_item_1, items);
        this.context = context;
        this.itemsList = items;
    }

    /**
     * Holder for the list items.
     */
    private class ViewHolder{
        TextView titleText;
        Button deleteButton;
    }

    /**
     *
     * @param position
     * @param convertView
     * @param parent
     * @return
     */
    public View getView(int position, View convertView, ViewGroup parent) {
        ViewHolder holder = null;
        View line = null;
        String item = (String)getItem(position);
        View viewToUse = null;

        // This block exists to inflate the settings list item conditionally based on whether
        // we want to support a grid or list view.
        LayoutInflater mInflater = (LayoutInflater) context
                .getSystemService(Activity.LAYOUT_INFLATER_SERVICE);

        viewToUse = mInflater.inflate(R.layout.wifi_list_item, null);
        holder = new ViewHolder();
        holder.titleText = (TextView)viewToUse.findViewById(R.id.titleText);
        holder.deleteButton = (Button)viewToUse.findViewById(R.id.deleteButton);
        viewToUse.setTag(holder);

        line = (View)viewToUse.findViewById(R.id.line);
        holder.titleText.setText(item);

        holder.deleteButton.setOnClickListener(new View.OnClickListener(){
            @Override
            public void onClick(View v) {
                View parentRow = (View) v.getParent();
                ListView listView = (ListView) parentRow.getParent();
                final int position = listView.getPositionForView(parentRow);
                deleteRegistry(position);
            }
        });

        if ( item.toString() == "No Devices") {
            line.setVisibility(View.INVISIBLE);
            RelativeLayout.LayoutParams params =    new RelativeLayout.LayoutParams
                    ((int) RelativeLayout.LayoutParams.WRAP_CONTENT, (int) RelativeLayout.LayoutParams.WRAP_CONTENT);
            params.addRule(RelativeLayout.CENTER_VERTICAL);
            params.addRule(RelativeLayout.CENTER_HORIZONTAL);
            holder.titleText.setLayoutParams(params);
        }

        return viewToUse;
    }

    //Elimina el Wifi en el indice "index" de la lista
    public void deleteRegistry(int index) {
        String message;
        String request = "$DELETE_NETWORK$" + itemsList.get(index);
        String response = GlobalObjectManager.bluetoothHelper.makeRequest(request);
        if(response != null && response.equals("200")){
            itemsList.remove(index);
            this.notifyDataSetChanged();
            message = response;
        }else{
            message = "Ha ocurrido un error al tratar de eliminar la red WiFi: " + itemsList.get(index);
        }
        Toast.makeText(context, message, Toast.LENGTH_LONG).show();
    }

    public void setList(List items){
        itemsList = items;
        this.notifyDataSetChanged();
    }

}