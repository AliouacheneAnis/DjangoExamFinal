from django.shortcuts import render
from django.http import HttpResponse
from ExamFinal.models import BME, Motor
from rest_framework import viewsets
from rest_framework import permissions
from ExamFinal.serializers import MotorSerializer, BMESerializer



""" views pour handle http post de l'objet qui capte temperature et humidity
    puis sauvegarder la donnee recu dans la base de donnees """ 
def postbme(request): 

    print(request.POST)

    IDcpt = request.POST.get("Capteur1")
    IDdata = request.POST.get("IDdatabme")
    tmp = request.POST.get("tmp")
    hum = request.POST.get("hum")
    Bme = BME(IDcapteur=IDcpt, IDdata = IDdata, tmp = tmp, hum = hum)
    Bme.save()

    return HttpResponse('<h1>Donnees Sauvegarger avec success</h1>');

""" views pour handle http post de l'objet qui utilise les bouton  
    puis sauvegarder les donnees recu dans la base de donnees """ 
def postmotor(request):
    print(request.POST)
    IDcpt2 = request.POST.get("Capteur2")
    IDdata2 = request.POST.get("IDdatamotor")
    btn1 = request.POST.get("btn1")
    btn2 = request.POST.get("btn2")
    m = Motor(IDcapteur=IDcpt2, IDdata = IDdata2, btn1 = btn1, btn2 = btn2)
    m.save()

    return HttpResponse('<h1>Donnees Sauvegarger avec success</h1>');

#endpoint 
class MotorViewSet(viewsets.ModelViewSet):
    """
    API endpoint that allows users to be viewed or edited.
    """
    #Recuperer dernier Object 
    queryset = Motor.objects.all().order_by('-id')[:1]
    serializer_class = MotorSerializer

#endpoint 
class BMEViewSet(viewsets.ModelViewSet):
    """
    API endpoint that allows users to be viewed or edited.
    """
    #Recuperer dernier Object 
    queryset = BME.objects.all().order_by('-id')[:1]
    serializer_class = BMESerializer