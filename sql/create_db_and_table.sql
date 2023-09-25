CREATE DATABASE example;

SHOW DATABASES;

USE example;
USE world;

DROP DATABASE example;

CREATE DATABASE example;
USE example;

CREATE TABLE users (
    user_id INT,
    username VARCHAR(50),
    email VARCHAR(100),
    birthdate DATE,
    registration_date TIMESTAMP
);

SHOW TABLES;
SHOW TABLES FROM world;

DESC users;
DESCRIBE users;

SHOW TABLES;
RENAME TABLE users to newusers;
SHOW TABLES;

DESC newusers;

CREATE TABLE users (
    user_id INT PRIMARY KEY AUTO_INCREMENT,
    username VARCHAR(50) NOT NULL,
    email VARCHAR(100) UNIQUE,
    birthdate DATE,
    registration_date TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);

CREATE TABLE orders (
  id INT NOT NULL AUTO_INCREMENT,
  customer_id INT NOT NULL,
  status VARCHAR(255) NOT NULL DEFAULT 'pending',
  PRIMARY KEY (id)
);

CREATE TABLE categories (
  id INT NOT NULL AUTO_INCREMENT,
  name VARCHAR(255) NOT NULL,
  PRIMARY KEY (id)
);

CREATE TABLE products (
  id INT NOT NULL AUTO_INCREMENT,
  name VARCHAR(255) NOT NULL,
  category_id INT NOT NULL,
  PRIMARY KEY (id),
  FOREIGN KEY (category_id) REFERENCES categories (id)
);

SHOW TABLES;
DESC newusers;
DESC orders;
DESC users;

ALTER TABLE users ADD COLUMN age INT;
DESC users;
ALTER TABLE users DROP COLUMN age;
DESC users;

TRUNCATE users;
SHOW TABLES;

DROP TABLE users;
SHOW TABLES;
