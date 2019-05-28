var style = new ol.style.Style({
    image: new ol.style.Circle({
        radius: 5,
        fill: new ol.style.Fill({
            color: '#ffa500'
        }),
        stroke: new ol.style.Stroke({
            color: 'red',
            width: 0.5
        })
    })
});
var vectorSource = new ol.source.Vector({});
var vectorSourcePoint = new ol.source.Vector({});
var map = new ol.Map({
    layers: [
        new ol.layer.Tile({
            source: new ol.source.OSM()
        }),
        new ol.layer.Vector({
            source: vectorSource
        }),
        new ol.layer.Vector({
            source: vectorSourcePoint,
            style: style
        })
    ],
    target: 'map',
    view: new ol.View({})
});

var obtainedData = [];

$.ajax({
    url: window.location.origin + "/get-all-data",
    type: 'get',
    headers: {
        'Access-Control-Allow-Origin': '*'
    },
    success: function(result) {
        obtainedData = result;
        fillDevicesSelect();
        drawDeviceCoordinates(null);
    }
});

function drawDeviceCoordinates(deviceName) {
    vectorSource.clear();
    vectorSourcePoint.clear();
    if (deviceName == null || deviceName == 'null') {
        map.getView().setCenter(ol.proj.transform([0, 0], 'EPSG:4326', 'EPSG:3857'));
        map.getView().setZoom(1);
        return;
    }
    var points = [];
    var latitudesSum = 0;
    var longitudesSum = 0;
    var elementsSum = 0;
    obtainedData.forEach(element => {
        if (element.device == deviceName) {
            latitudesSum += element.latitude;
            longitudesSum += element.longitude;
            elementsSum += 1;
            points.push(ol.proj.transform([element.longitude, element.latitude], 'EPSG:4326', 'EPSG:3857'));
            var point = new ol.geom.Point([element.longitude, element.latitude]).transform('EPSG:4326', 'EPSG:3857');
            var fea = new ol.Feature({
                geometry: point
            });
            vectorSourcePoint.addFeature(fea);
        }
    });
    map.getView().setCenter(ol.proj.transform([longitudesSum / elementsSum, latitudesSum / elementsSum], 'EPSG:4326', 'EPSG:3857'));
    map.getView().setZoom(17);
    var thing = new ol.geom.LineString(points);
    var featurething = new ol.Feature({
        name: "Thing",
        geometry: thing,
        style: new ol.style.Style({
            stroke: new ol.style.Stroke({
                color: 'red'
            })
        })
    });
    vectorSource.addFeature(featurething);
}

function fillDevicesSelect() {
    $('#devices').empty();
    $('#devices').append('<option value="' + null + '">Seleccione un dispositivo</option>');
    var devices = [];
    obtainedData.forEach(element => {
        if (!devices.includes(element.device)) {
            devices.push(element.device);
            $('#devices').append('<option value="' + element.device + '">' + element.device + '</option>');
        }
    });
}

//Cuando cambia el select de dispositivos
$("#devices").change(function() {
    var deviceName = $('#devices option:selected').val();
    drawDeviceCoordinates(deviceName);
});