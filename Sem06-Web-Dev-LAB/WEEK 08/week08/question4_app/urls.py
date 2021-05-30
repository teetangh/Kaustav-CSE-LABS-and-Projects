from django.contrib import admin
from django.urls import path, include

from . import views
from .views import RodeSprinterAmenity, RodeSprinterAmenityDetail, RodeSprinterAmenityNameFilter, RodeSprinterAmenityLocationFilter

urlpatterns = [
    path("RodeSprinterAmenity/", RodeSprinterAmenity),
    path("RodeSprinterAmenityDetail/<int:pk>/", RodeSprinterAmenityDetail),

    path("RodeSprinterAmenity/name/<str:name>/", RodeSprinterAmenityNameFilter),
    path("RodeSprinterAmenity/location/<str:location>/",
         RodeSprinterAmenityLocationFilter),
]
