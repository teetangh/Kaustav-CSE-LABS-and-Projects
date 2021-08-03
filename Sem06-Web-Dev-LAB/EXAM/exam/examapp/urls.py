from django.urls import path
from . import views

urlpatterns = [
    path("admin/", views.index, name="index"),
    path("success_view", views.success_view, name="success_view"),
    path("filter", views.filter, name="filter"),
    path("ad_view", views.index, name="index"),

]
