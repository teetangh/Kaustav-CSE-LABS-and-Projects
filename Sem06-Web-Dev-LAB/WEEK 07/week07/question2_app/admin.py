from django.contrib import admin
from . import models

# Register your models here.
admin.site.register(models.PersonModel)
admin.site.register(models.WorksModel)
admin.site.register(models.LivesModel)