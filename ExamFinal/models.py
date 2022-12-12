from django.db import models

# Create your models here.

# listings/models.py

class BME(models.Model):
    IDcapteur = models.fields.IntegerField()
    IDdata = models.fields.BigIntegerField()
    tmp = models.fields.FloatField()
    hum = models.fields.FloatField()


class Motor(models.Model):
    IDcapteur = models.fields.IntegerField()
    IDdata = models.fields.BigIntegerField()
    btn1 = models.fields.CharField(max_length=3)
    btn2 = models.fields.CharField(max_length=3)

