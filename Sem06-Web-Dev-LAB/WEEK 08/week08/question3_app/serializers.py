from rest_framework import serializers
from .models import RomatoRestaurantModel


class RomatoRestaurantSerializer(serializers.ModelSerializer):

    class Meta:
        model = RomatoRestaurantModel
        fields = "__all__"
