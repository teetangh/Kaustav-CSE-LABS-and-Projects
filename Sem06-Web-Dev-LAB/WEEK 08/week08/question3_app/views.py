from django.shortcuts import render
from django.http import HttpResponse, JsonResponse

from rest_framework.decorators import api_view
from rest_framework.response import Response
from rest_framework import status

from .models import RomatoRestaurantModel
from .serializers import RomatoRestaurantSerializer

###########################################################################################


@api_view(["GET", "POST"])
def restaurant_location(request):

    if request.method == "GET":
        print("=======  GET =====")
        rides = RomatoRestaurantModel.objects.all()
        serializer = RomatoRestaurantSerializer(rides, many=True)
        return Response(serializer.data)

    elif request.method == "POST":
        serializer = RomatoRestaurantSerializer(data=request.data)
        if serializer.is_valid():
            serializer.save()
            return Response(serializer.data, status=status.HTTP_201_CREATED)
        return Response(serializer.errors, status=status.HTTP_400_BAD_REQUEST)


@api_view(["GET", "PUT", "DELETE"])
def restaurant_location_detail(request, pk):
    try:
        ride = RomatoRestaurantModel.objects.get(pk=pk)
    except RomatoRestaurantModel.DoesNotExist:
        return Response(status=status.HTTP_404_NOT_FOUND)

    if request.method == "GET":
        serializer = RomatoRestaurantSerializer(ride)
        return Response(serializer.data)

    elif request.method == "PUT":
        serializer = RomatoRestaurantSerializer(ride, data=request.data)

        if serializer.is_valid():
            serializer.save()
            return Response(serializer.data)
        return JsonResponse(serializer.errors, status=status.HTTP_400_BAD_REQUEST)

    elif request.method == "DELETE":
        ride.delete()
        return Response(status=status.HTTP_204_NO_CONTENT)
