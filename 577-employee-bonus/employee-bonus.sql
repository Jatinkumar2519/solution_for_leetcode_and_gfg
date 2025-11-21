# Write your MySQL query statement below
select name ,bonus from Employee as E
left join Bonus as B
on B.empId = E.empId
where bonus is null or bonus < 1000