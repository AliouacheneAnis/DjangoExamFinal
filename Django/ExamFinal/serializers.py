from rest_framework import serializers
from ExamFinal.models import Motor, BME

class MotorSerializer(serializers.HyperlinkedModelSerializer):
    class Meta:
        model = Motor
        fields = ('IDcapteur','IDdata','btn1','btn2')

class BMESerializer(serializers.HyperlinkedModelSerializer):
    class Meta:
        model = BME
        fields = ('IDcapteur','IDdata', 'tmp','hum')