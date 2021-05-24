-- SQLite
.shell clear;
DROP TABLE question1_app_car;
CREATE TABLE question1_app_car (id TEXT PRIMARY KEY, car_name TEXT NOT NULL);
PRAGMA table_info([question1_app_car]);
INSERT INTO question1_app_car(id, car_name)
VALUES ("01", "Bmw"),
    ("02", "Audi"),
    ("03", "Volvo");
SELECT id
FROM question1_app_car;