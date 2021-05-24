from django.urls import path, include
from . import views

urlpatterns = [
    path("", views.index, name="index"),
    path("/success_view", views.success_view, name="home_view"),
]
