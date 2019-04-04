import subprocess

DEPLOY_SCRIPTS = [
    ("./../../src/boot.py","boot.py"),
    ("./../../src/main.py","main.py"),
    ("./../../src/Configuracion.py","Configuracion.py"),
    ("./../../src/HttpRequests.py","HttpRequests.py"),
    ("./../../src/ConectorWiFi.py","ConectorWiFi.py"),
    ("./../../src/ImportadorMultiplataforma.py","ImportadorMultiplataforma.py"),
    ("webrepl_cfg.py","webrepl_cfg.py") #PARA CONFIGURAR WEBREPL
]

for x in DEPLOY_SCRIPTS:
    print("TRANSFIRIENDO ARCHIVO",DEPLOY_SCRIPTS.index(x)+1,"DE",len(DEPLOY_SCRIPTS))
    print("Desde:",x[0],"a:",x[1])
    bashCommand = "python webrepl_cli.py -p Passw0rd "+x[0]+" 192.168.4.1:8266:"+x[1]
    process = subprocess.Popen(bashCommand.split(), stdout=subprocess.PIPE)
    output, error = process.communicate()
    lines = output.splitlines()
    print(lines[len(lines)-1])
    print("\n--------------------------------------------------------------------\n")
print("LA TRANSFERENCIA DE ARCHIVOS HA FINALIZADO CON EXITO!\n")