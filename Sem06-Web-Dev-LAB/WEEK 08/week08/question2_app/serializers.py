from rest_framework import serializers
from .models import OLARideModel


class OLARideSerializer(serializers.ModelSerializer):

    class Meta:
        model = OLARideModel
        fields = "__all__"
