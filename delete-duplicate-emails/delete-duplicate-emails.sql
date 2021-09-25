# Write your MySQL query statement below
DELETE FROM Person where id not in (SELECT * FROM(
    SELECT MIN(Id) FROM Person GROUP BY Email) as p);