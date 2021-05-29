from django.urls import path
from . import views

urlpatterns = [
    path("", views.index, name="index"),
    path("/success_view", views.success_view, name="success_view"),
]
