package com.example.gpstracker;

import android.support.v4.app.FragmentActivity;
import android.os.Bundle;

import com.google.android.gms.maps.model.CameraPosition;
import com.google.android.gms.maps.model.Polyline;
import com.google.android.gms.maps.model.PolylineOptions;
import android.graphics.Color;
import com.google.android.gms.maps.CameraUpdateFactory;
import com.google.android.gms.maps.GoogleMap;
import com.google.android.gms.maps.OnMapReadyCallback;
import com.google.android.gms.maps.SupportMapFragment;
import com.google.android.gms.maps.model.LatLng;
import com.google.android.gms.maps.model.MarkerOptions;

public class MapsActivity extends FragmentActivity implements OnMapReadyCallback {

    private GoogleMap mMap;
    public static LatLng partida = new LatLng(-34.616824, -58.555086);
    public static LatLng destino = new LatLng(-34.605013, -58.564273 );

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_maps);
        // Obtain the SupportMapFragment and get notified when the map is ready to be used.
        SupportMapFragment mapFragment = (SupportMapFragment) getSupportFragmentManager()
                .findFragmentById(R.id.map);
        mapFragment.getMapAsync(this);
    }
    /*

        /**
         * Manipulates the map once available.
         * This callback is triggered when the map is ready to be used.
         * This is where we can add markers or lines, add listeners or move the camera. In this case,
         * we just add a marker near Sydney, Australia.
         * If Google Play services is not installed on the device, the user will be prompted to install
         * it inside the SupportMapFragment. This method will only be triggered once the user has
         * installed Google Play services and returned to the app.
         */
    @Override
    public void onMapReady(GoogleMap googleMap) {
        mMap = googleMap;
        //agrega marcador al lugar que designe
        mMap.addMarker(new MarkerOptions().position(partida).title("Partida"));
        mMap.addMarker(new MarkerOptions().position(destino).title("Destino"));
        //mueve el centro de la camara
     //   mMap.moveCamera(CameraUpdateFactory.newLatLngZoom(partida,15));
        mMap.addMarker(new MarkerOptions().position(destino).title("Destino"));

        //efecto de camara
        CameraPosition googlePlex = CameraPosition.builder()
                .target(new LatLng(-34.608131, -58.565142))
                .zoom(15)
                .bearing(0)
                .tilt(45)
                .build();
        mMap.animateCamera(CameraUpdateFactory.newCameraPosition(googlePlex), 5000, null);

        //grafico ruta
        Polyline polyline1 = mMap.addPolyline(new  PolylineOptions()
                .width(7)
                .color(Color.BLUE)
                .geodesic(true)
                .clickable(true)
                .add(
                        new LatLng(-34.616824, -58.555086),
                        new LatLng(-34.616283, -58.557862),
                        new LatLng(-34.615435, -58.557862),
                        new LatLng(-34.615107, -58.562809),
                        new LatLng(-34.609041, -58.562276),
                       // new LatLng(-34.609085, -58.560688),
                        new LatLng(-34.605368, -58.561921),
                        new LatLng(-34.605013, -58.564273)

                )
        );
        /* condicion para permisos
        if (ActivityCompat.checkSelfPermission(this, Manifest.permission.ACCESS_FINE_LOCATION) != PackageManager.PERMISSION_GRANTED && ActivityCompat.checkSelfPermission(this, Manifest.permission.ACCESS_COARSE_LOCATION) != PackageManager.PERMISSION_GRANTED) {
            // TODO: Consider calling
            //    ActivityCompat#requestPermissions
            // here to request the missing permissions, and then overriding
            //   public void onRequestPermissionsResult(int requestCode, String[] permissions,
            //                                          int[] grantResults)
            // to handle the case where the user grants the permission. See the documentation
            // for ActivityCompat#requestPermissions for more details.
            return;
        }
        mMap.setMyLocationEnabled(false);
        */
    }
}
