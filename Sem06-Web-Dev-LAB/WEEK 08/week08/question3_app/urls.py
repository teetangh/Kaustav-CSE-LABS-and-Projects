from django.contrib import admin
from django.urls import path, include

from . import views
from .views import restaurant_location, restaurant_location_detail

urlpatterns = [
    path("restaurant_location/", restaurant_location),
    path("restaurant_location_detail/<int:pk>/", restaurant_location_detail)

]
