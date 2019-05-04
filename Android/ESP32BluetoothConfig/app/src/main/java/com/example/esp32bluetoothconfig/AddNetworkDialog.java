package com.example.esp32bluetoothconfig;

import android.app.AlertDialog;
import android.app.Dialog;
import android.content.Context;
import android.content.DialogInterface;
import android.os.Bundle;
import android.support.annotation.Nullable;
import android.support.v7.app.AppCompatDialogFragment;
import android.view.LayoutInflater;
import android.view.View;
import android.widget.EditText;
import android.widget.Toast;

public class AddNetworkDialog extends AppCompatDialogFragment {

    private EditText SSIDTextEdit;
    private EditText passwordTextEdit;
    private AddNetworkDialogListener listener;

    @Override
    public Dialog onCreateDialog(Bundle savedInstanceState) {
        AlertDialog.Builder builder = new AlertDialog.Builder(getActivity(), R.style.DarkDialog);

        LayoutInflater inflater = getActivity().getLayoutInflater();
        View view = inflater.inflate(R.layout.add_network_dialog, null);

        builder.setView(view)
                .setTitle("Agregar red WiFi")
                .setNegativeButton("Cancelar", new DialogInterface.OnClickListener() {
                    @Override
                    public void onClick(DialogInterface dialog, int which) {

                    }
                })
                .setPositiveButton("Guardar", new DialogInterface.OnClickListener() {
                    @Override
                    public void onClick(DialogInterface dialog, int which) {
                        String SSID = SSIDTextEdit.getText().toString();
                        String password = passwordTextEdit.getText().toString();
                        if(SSID.length() == 0 || password.length() == 0){
                            Toast.makeText(getContext(), "Tando el campo SSID como Password son requeridos.", Toast.LENGTH_LONG).show();
                            return;
                        }
                        listener.applyTexts(SSID, password);
                    }
                });

        SSIDTextEdit = view.findViewById(R.id.SSIDTextEdit);
        passwordTextEdit = view.findViewById(R.id.passwordTextEdit);

        return builder.create();
    }

    @Override
    public void onAttach(Context context) {
        super.onAttach(context);
        try{
            listener = (AddNetworkDialogListener) context;
        }catch (ClassCastException e){
            throw new ClassCastException(context.toString() + "must implement AddNetworkDialogListener");
        }
    }

    public interface  AddNetworkDialogListener{
        void applyTexts(String SSID, String password);
    }
}
