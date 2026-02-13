CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
      # Write your MySQL query statement below
        select distinct salary from Employee e1
        where N - 1 in (select count(distinct salary) from Employee e2
                        where e1.salary < e2.salary)
  );
END