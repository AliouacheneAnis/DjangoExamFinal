from django.db import models

# Create your models here.

# listings/models.py

class BME(models.Model):
    IDcapteur = models.fields.IntegerField()
    tmp = models.fields.FloatField()
    hum = models.fields.FloatField()


class Motor(models.Model):
    IDcapteur = models.fields.IntegerField()
    btn1 = models.fields.IntegerField()
    btn2 = models.fields.IntegerField()

