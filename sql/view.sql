CREATE DATABASE IF NOT EXISTS example;
USE example;

CREATE TABLE IF NOT EXISTS users (
    id INT AUTO_INCREMENT PRIMARY KEY,
    person VARCHAR(255) NOT NULL,
    age INT,
    city VARCHAR(255),
    email VARCHAR(255) NOT NULL
);

INSERT INTO users (person, age, city, email) VALUES
    ('John', 25, 'New York', 'john@example.com'),
    ('Alice', 30, 'Los Angeles', 'alice@example.com'),
    ('Bob', 28, 'Chicago', 'bob@example.com'),
    ('Eve', 35, 'San Francisco', 'eve@example.com'),
    ('Charlie', 22, 'Houston', 'charlie@example.com');

SELECT * FROM users;

CREATE VIEW example_view AS
SELECT id, person, age, email FROM users WHERE age >= 28;

SELECT * FROM example_view;

INSERT INTO example_view (person, age, email) VALUES ('Frank', 40, 'frank@example.com');
-- 불가능
INSERT INTO example_view (person, city) VALUES (40, 'Miami');

UPDATE example_view SET person = 'UpdatedName' WHERE id = 2;

DELETE FROM example_view WHERE id = 3;

DROP VIEW example_view;

-- 집계함수를 이용한 view
CREATE VIEW age_average_view AS
SELECT AVG(age) AS average_age
FROM users;

SELECT * FROM age_average_view;

-- 불가능
DELETE FROM age_average_view;

CREATE VIEW city_population_view AS
SELECT city, COUNT(person) AS population
FROM users
GROUP BY city;

SELECT * FROM city_population_view;

-- 불가능
UPDATE city_population_view SET population = 2 WHERE city = 'New York';

-- 나이(age)의 최대값과 최소값을 계산한 뷰
CREATE VIEW age_statistics_view AS
SELECT MAX(age) AS max_age, MIN(age) AS min_age
FROM users;
SELECT * FROM age_statistics_view;
