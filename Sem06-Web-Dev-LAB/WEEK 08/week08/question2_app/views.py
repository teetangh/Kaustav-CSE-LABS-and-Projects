from django.shortcuts import render
from django.http import HttpResponse, JsonResponse

from rest_framework.decorators import api_view
from rest_framework.response import Response
from rest_framework import status

from .models import OLARideModel
from .serializers import OLARideSerializer


@api_view(["GET", "POST"])
def rides_list(request):

    if request.method == "GET":
        rides = OLARideModel.objects.all()
        serializer = OLARideSerializer(rides, many=True)
        return Response(serializer.data)

    elif request.method == "POST":
        serializer = OLARideSerializer(data=request.data)
        if serializer.is_valid():
            serializer.save()
            return Response(serializer.data, status=status.HTTP_201_CREATED)
        return Response(serializer.errors, status=status.HTTP_400_BAD_REQUEST)


@api_view(["GET", "PUT", "DELETE"])
def rides_detail(request, pk):
    try:
        ride = OLARideModel.objects.get(pk=pk)
    except OLARideModel.DoesNotExist:
        return Response(status=status.HTTP_404_NOT_FOUND)

    if request.method == "GET":
        serializer = OLARideSerializer(ride)
        return Response(serializer.data)

    elif request.method == "PUT":
        serializer = OLARideSerializer(ride, data=request.data)

        if serializer.is_valid():
            serializer.save()
            return Response(serializer.data)
        return JsonResponse(serializer.errors, status=status.HTTP_400_BAD_REQUEST)

    elif request.method == "DELETE":
        ride.delete()
        return Response(status=status.HTTP_204_NO_CONTENT)
