CREATE TABLE customers (
  id INT AUTO_INCREMENT PRIMARY KEY,
  name VARCHAR(255),
  age INT,
  address VARCHAR(255)
);

INSERT INTO customers (name, age, address)
VALUES
  ('김가나', 30, '서울시 강남구'),
  ('이다라', 25, '부산시 해운대구'),
  ('박마바', 40, '대구광역시 중구'),
  ('김사아', 50, '광주광역시 서구'),
  ('이자차', 60, '울산광역시 남구'),
  ('박카타', 70, '제주특별자치도 제주시'),
  ('강파하', 80, '강원도 춘천시'),
  ('이가나', 90, '충청북도 청주시'),
  ('박다라', 100, '전라북도 전주시');


CREATE TABLE orders (
  id INT AUTO_INCREMENT PRIMARY KEY,
  customer_id INT,
  product_id INT,
  quantity INT,
  amount INT
);

INSERT INTO orders (customer_id, product_id, quantity, amount)
VALUES
  (1, 1, 10, 1000),
  (2, 2, 20, 2000),
  (2, 3, 30, 3000),
  (3, 4, 40, 4000),
  (3, 5, 50, 5000),
  (4, 6, 60, 6000),
  (5, 7, 70, 7000),
  (10, 8, 80, 8000),
  (11, 9, 90, 9000);

  
SELECT * FROM customers;
SELECT * FROM orders;

SELECT
  customers.name,
  customers.age,
  customers.address,
  orders.id,
  orders.product_id,
  orders.quantity,
  orders.amount
FROM customers
INNER JOIN orders
ON customers.id = orders.customer_id;


-- 잘못된 예
SELECT
  name,
  age,
  address,
  id,
  product_id,
  quantity,
  amount
FROM customers
INNER JOIN orders
ON customers.id = orders.customer_id;


SELECT
  customers.name,
  customers.age,
  customers.address
FROM customers
INNER JOIN orders
ON customers.id = orders.customer_id
WHERE orders.amount >= 5000;

SELECT customers.name, orders.id AS order_id, orders.product_id, orders.quantity, orders.amount
FROM customers
LEFT OUTER JOIN orders ON customers.id = orders.customer_id;

SELECT customers.name, orders.id AS order_id, orders.product_id, orders.quantity, orders.amount
FROM customers
RIGHT OUTER JOIN orders ON customers.id = orders.customer_id;

SELECT customers.name, orders.id AS order_id, orders.product_id, orders.quantity, orders.amount
FROM customers
LEFT OUTER JOIN orders ON customers.id = orders.customer_id
UNION
SELECT customers.name, orders.id AS order_id, orders.product_id, orders.quantity, orders.amount
FROM customers
RIGHT OUTER JOIN orders ON customers.id = orders.customer_id;


