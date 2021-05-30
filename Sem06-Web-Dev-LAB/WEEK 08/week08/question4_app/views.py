from django.shortcuts import render
from django.http import HttpResponse, JsonResponse

from rest_framework.decorators import api_view
from rest_framework.response import Response
from rest_framework import status

from .models import RodeSprinterAmenityModel
from .serializers import RodeSprinterAmenitySerializer

###########################################################################################


@api_view(["GET", "POST"])
def RodeSprinterAmenity(request):

    if request.method == "GET":
        print("=======  GET =====")
        rides = RodeSprinterAmenityModel.objects.all()
        serializer = RodeSprinterAmenitySerializer(rides, many=True)
        return Response(serializer.data)

    elif request.method == "POST":
        serializer = RodeSprinterAmenitySerializer(data=request.data)
        if serializer.is_valid():
            serializer.save()
            return Response(serializer.data, status=status.HTTP_201_CREATED)
        return Response(serializer.errors, status=status.HTTP_400_BAD_REQUEST)


@api_view(["GET", "PUT", "DELETE"])
def RodeSprinterAmenityDetail(request, pk):
    try:
        ride = RodeSprinterAmenityModel.objects.get(pk=pk)
    except RodeSprinterAmenityModel.DoesNotExist:
        return Response(status=status.HTTP_404_NOT_FOUND)

    if request.method == "GET":
        serializer = RodeSprinterAmenitySerializer(ride)
        return Response(serializer.data)

    elif request.method == "PUT":
        serializer = RodeSprinterAmenitySerializer(ride, data=request.data)

        if serializer.is_valid():
            serializer.save()
            return Response(serializer.data)
        return JsonResponse(serializer.errors, status=status.HTTP_400_BAD_REQUEST)

    elif request.method == "DELETE":
        ride.delete()
        return Response(status=status.HTTP_204_NO_CONTENT)


@api_view(["GET"])
def RodeSprinterAmenityNameFilter(request, name):

    if request.method == "GET":
        print("=======  FILTER =====", name)
        rides = RodeSprinterAmenityModel.objects.filter(name=name)
        serializer = RodeSprinterAmenitySerializer(rides, many=True)
        return Response(serializer.data)


@api_view(["GET"])
def RodeSprinterAmenityLocationFilter(request, location):

    if request.method == "GET":
        print("=======  FILTER =====", location)
        rides = RodeSprinterAmenityModel.objects.filter(location=location)
        serializer = RodeSprinterAmenitySerializer(rides, many=True)
        return Response(serializer.data)
