from django.urls import path, include
from . import views

urlpatterns = [
    path("", views.firstPage, name="home"),
    path("/firstPage", views.firstPage, name="firstPage"),
    path("/secondPage", views.secondPage, name="secondPage")
]
