from django.db import models

# model pour les donnees de temperature 
class BME(models.Model):
    IDcapteur = models.fields.IntegerField()
    IDdata = models.fields.BigIntegerField()
    tmp = models.fields.FloatField()
    hum = models.fields.FloatField()

# model pour le status des boutons
class Motor(models.Model):
    IDcapteur = models.fields.IntegerField()
    IDdata = models.fields.BigIntegerField()
    btn1 = models.fields.CharField(max_length=3)
    btn2 = models.fields.CharField(max_length=3)

