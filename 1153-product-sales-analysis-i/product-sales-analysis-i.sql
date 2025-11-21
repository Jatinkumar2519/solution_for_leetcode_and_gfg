# Write your MySQL query statement below
select product_name, year , price from Sales as S
join Product as P
on S.product_id = P.product_id