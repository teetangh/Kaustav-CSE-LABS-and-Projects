from django.contrib import admin
from django.urls import path, include

from . import views
from .views import rides_list, rides_detail

# urlpatterns = [
#     path("rides/", rides_list),
#     path("detail/<int:pk>/", rides_detail)
# ]
urlpatterns = [
    path("", views.index, name="index"),
]
