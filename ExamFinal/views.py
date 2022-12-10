from django.shortcuts import render
from django.http import HttpResponse

# Create your views here.


def post(request):
    print(request.POST)
    return HttpResponse('<h1>Donnees Sauvegarger avec success</h1>');