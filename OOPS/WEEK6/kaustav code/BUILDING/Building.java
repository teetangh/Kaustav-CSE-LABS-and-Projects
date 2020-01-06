package com.course.structure;

class Building {
     double squarefootage;
     double stories;

     void setSquarefootage(double squarefootage) {
          this.squarefootage = squarefootage;
     }

     void setStories(double stories) {
          this.stories = stories;
     }

     double getSquarefootage() {
          return (this.squarefootage);
     }

     double getStories() {
          return (this.stories);
     }
}

class House extends Building {
     int bedrooms;
     int baths;

     void setBedrooms(int bedrooms) {
          this.bedrooms = bedrooms;
     }

     void setBaths(int baths) {
          this.baths = baths;
     }

     double getBedrooms() {
          return (this.bedrooms);
     }

     double getBaths() {
          return (this.baths);
     }
}

class School extends Building {
     int classrooms;
     String gradelevel;

     void setClassrooms(int classrooms) {
          this.classrooms = classrooms;
     }

     void setGradelevel(String gradelevel) {
          this.gradelevel = gradelevel;
     }

     double getClassrooms() {
          return (this.classrooms);
     }

     String getGradelevel() {
          return (this.gradelevel);
     }
}
