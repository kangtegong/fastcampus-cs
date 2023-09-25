SHOW DATABASES;
CREATE DATABASE example;
USE example;
SHOW databases;

CREATE TABLE categories (
  id INT NOT NULL AUTO_INCREMENT,
  name VARCHAR(255) NOT NULL,
  PRIMARY KEY (id)
);

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

SHOW INDEX FROM categories;

CREATE INDEX idx_category_name ON categories(name);


SHOW INDEX FROM categories;

INSERT INTO categories(name) VALUES('Category 7');
CREATE UNIQUE INDEX idx_category_name2 ON categories(name);

DELETE FROM categories where name='Category 7';
SHOW INDEX FROM categories;

DROP INDEX idx_category_name2 ON categories;

EXPLAIN SELECT * FROM categories WHERE name= 'Category 7';
DROP INDEX idx_category_name ON categories;
EXPLAIN SELECT * FROM categories WHERE name= 'Category 7';
