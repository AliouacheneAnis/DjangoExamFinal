from django.shortcuts import render
from django.http import HttpResponse
from ExamFinal.models import BME, Motor


# Create your views here.


def post(request):
    print(request.POST)
    IDcpt = request.POST.get("Capteur1")
    tmp = request.POST.get("tmp")
    hum = request.POST.get("hum")
    IDcpt2 = request.POST.get("Capteur2")
    btn1 = request.POST.get("btn1")
    btn2 = request.POST.get("btn2")
    Bme = BME(IDcapteur=IDcpt, tmp = tmp, hum = hum)
    Bme.save()
    m = Motor(IDcapteur=IDcpt2, btn1 = btn1, btn2 = btn2)
    m.save()

    return HttpResponse('<h1>Donnees Sauvegarger avec success</h1>');