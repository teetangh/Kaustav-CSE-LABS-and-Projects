from .models import RodeSprinterAmenityModel
from rest_framework import serializers

class RodeSprinterAmenitySerializer(serializers.ModelSerializer):

    class Meta:
        model = RodeSprinterAmenityModel
        fields = "__all__"
