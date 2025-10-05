# Write your MySQL query statement below
select name Employee from Employee a where a.salary > (select salary from Employee b where b.id = a.managerId)