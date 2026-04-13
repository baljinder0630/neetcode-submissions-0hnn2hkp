-- Write your query below
Select c.name
from customers as c
left join orders as o
on o.customer_id =  c.id
where o.id is null;