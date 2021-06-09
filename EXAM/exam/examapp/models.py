from django.db import models


class StudentModel(models.Model):
    name = models.CharField(max_length=30, primary_key=True)
    regno = models.IntegerField()
    cgpa = models.FloatField()

    # def __str__(self):
    #     return "%s %d %f" % (self.name, self.regno, self.cgpa)
