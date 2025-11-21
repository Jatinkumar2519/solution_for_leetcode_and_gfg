# Write your MySQL query statement below
select unique_id,name from Employees as E
left join EmployeeUNI as R
on R.id = E.id