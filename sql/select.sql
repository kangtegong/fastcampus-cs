SHOW DATABASES;
CREATE DATABASE example;
USE example;
SHOW databases;

CREATE TABLE categories (
  id INT NOT NULL AUTO_INCREMENT,
  name VARCHAR(255) NOT NULL,
  PRIMARY KEY (id)
);

CREATE TABLE products (
  id INT NOT NULL AUTO_INCREMENT,
  name VARCHAR(255) NOT NULL,
  category_id INT NOT NULL,
  price INT NOT NULL,
  registration_date TIMESTAMP NOT NULL,
  PRIMARY KEY (id),
  FOREIGN KEY (category_id) REFERENCES categories (id)
);

show tables;
DESC categories;
DESC products;

INSERT INTO categories (name) VALUES
  ('Category 1'),
  ('Category 2'),
  ('Category 3'),
  ('Category 4'),
  ('Category 5'),
  ('Category 6'),
  ('Category 7'),
  ('Category 8'),
  ('Category 9'),
  ('Category 10');

SELECT * FROM categories;

INSERT INTO products (name, category_id, price, registration_date) VALUES
  ('apple', 1, 1000, '2023-09-20 10:00:00'),
  ('banana', 2, 800, '2023-09-20 11:30:00'),
  ('keyboard', 3, 1200, '2023-09-20 12:45:00'),
  ('monitor', 3, 1500, '2023-09-20 14:20:00'),
  ('small monitor', 2, 750, '2023-09-20 15:10:00'),
  ('big monitor', 4, 2000, '2023-09-20 16:40:00'),
  ('headphone', 3, 1350, '2023-09-20 18:00:00'),
  ('pizza', 1, 950, '2023-09-20 19:30:00'),
  ('chicken', 1, 1800, '2023-09-20 21:15:00'),
  ('glasses', 2, 1000, '2023-09-20 22:45:00');

SELECT * FROM products;

SELECT * FROM categories;
SELECT name FROM categories;

SELECT * FROM products;
SELECT name, price FROM products;

SELECT * FROM products WHERE category_id = 2;
SELECT * FROM products WHERE category_id != 2;
SELECT * FROM products WHERE category_id <> 2;

SELECT * FROM categories WHERE name = 'Category 3';
SELECT * FROM products WHERE name = 'apple';
SELECT * FROM products WHERE category_id IS NULL;

SELECT * FROM products WHERE price >= 1000;
SELECT * FROM products WHERE registration_date >= '2023-09-20 12:00:00';

SELECT * FROM products WHERE price >= 1000 AND category_id = 3;
SELECT * FROM categories WHERE id >= 5 AND id < 8;

SELECT category_id FROM products;
SELECT DISTINCT category_id FROM products;

SELECT id FROM categories;
SELECT id FROM categories ORDER BY id ASC;
SELECT id FROM categories ORDER BY id DESC;

SELECT * FROM products;
SELECT * FROM products ORDER BY price ASC;
SELECT * FROM products ORDER BY price DESC;
