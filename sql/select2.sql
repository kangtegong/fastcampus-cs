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

SELECT * FROM products;
SELECT COUNT(*) FROM products;
SELECT COUNT(*) AS totoal_products FROM products;
SELECT COUNT(*) AS expensive_products FROM products WHERE price > 1000;

SELECT price FROM products;
SELECT SUM(price) FROM products;
SELECT AVG(price) FROM products;

SELECT price FROM products;
SELECT COUNT(price) FROM products;
SELECT MAX(price) FROM products;
SELECT MIN(price) FROM products;

SELECT DISTINCT price FROM products;
SELECT COUNT(DISTINCT price) FROM products;
SELECT SUM(DISTINCT price) FROM products;
SELECT AVG(DISTINCT price) FROM products;
SELECT MAX(DISTINCT price) FROM products;
SELECT MIN(DISTINCT price) FROM products;


SELECT name FROM products WHERE name='monitor';

SELECT name FROM products WHERE name LIKE '_onitor';
SELECT name FROM products WHERE name LIKE '%monitor%';

SELECT category_id, count(*) FROM products GROUP BY category_id;

SELECT
  category_id,
  AVG(price) AS avg_price
FROM
  products
GROUP BY
  category_id;

-- 평균 가격이 1200 이상인 카테고리
SELECT
  category_id,
  AVG(price) AS avg_price
FROM
  products
GROUP BY
  category_id
HAVING
  avg_price >= 1200;
  
-- 가격이 평균 가격보다 높은 제품 
SELECT name, price FROM products
WHERE price > (
  SELECT AVG(price)
  FROM products
);


-- -----------------------------------------------------------------------------------


CREATE TABLE mytable (
	user_id INT NOT NULL,
    product_id INT NOT NULL,
    price INT NOT NULL,
    amount INT NOT NULL
);

INSERT INTO mytable (user_id, product_id, price, amount) VALUES
	(1, 1, 100, 1),
	(1, 2, 200, 2),
	(2, 1, 500, 1),
	(2, 2, 100, 2),
	(3, 1, 100, 1),
	(3, 2, 200, 1),
	(4, 1, 500, 1),
	(4, 2, 100, 1);

SELECT * FROM mytable;

-- GROUP BY & HAVING

SELECT user_id, SUM(price * amount)
FROM mytable
GROUP BY user_id;

SELECT user_id, SUM(price * amount)
FROM mytable
GROUP BY user_id
HAVING SUM(price * amount) > 500;


-- 가장 비싼 상품을 구매한 사용자 찾기
SELECT user_id
FROM mytable
WHERE (price * amount) = (
    SELECT MAX(price * amount)
    FROM mytable
);

-- 각 사용자가 가장 많이 구매한 상품 아이디찾기
SELECT user_id, product_id
FROM mytable
WHERE (user_id, amount) IN (
    SELECT user_id, MAX(amount)
    FROM mytable
    GROUP BY user_id
);


