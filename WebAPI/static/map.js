var vectorSource = new ol.source.Vector({});
var vectorSourcePoint = new ol.source.Vector({});
var style = new ol.style.Style({
    image: new ol.style.Circle({
        radius: 4,
        fill: new ol.style.Fill({
            color: '#ffa500'
        }),
        stroke: new ol.style.Stroke({
            color: 'red',
            width: 0.5
        })
    })
});

$.ajax({
    url: window.location.origin + "/get-all-data",
    type: 'get',
    headers: {
        'Access-Control-Allow-Origin': '*'
    },
    success: function (result) {
        result = JSON.parse(result);
        var points = drawDeviceCoordinates("NO_ESP_TEST", result)
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
});

function drawDeviceCoordinates(deviceName, dataArray) {
    var points = [];
    var latitudesSum = 0;
    var longitudesSum = 0;
    var elementsSum = 0;
    dataArray.forEach(element => {
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
    /*map.view = new ol.View({
        center: [latitudesSum / elementsSum, longitudesSum / elementsSum],
        zoom: 5
    });*/
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
        view: new ol.View({
            center: ol.proj.transform([longitudesSum / elementsSum, latitudesSum / elementsSum], 'EPSG:4326', 'EPSG:3857'),
            zoom: 15
        })
    });
    return points;
}