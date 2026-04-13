select c.customer_id, c.customer_name from customers as c
where c.customer_id in (
    select o.customer_id from orders as o
    where o.product_name = 'A'
)AND c.customer_id in(
    select o.customer_id from orders as o
    where o.product_name = 'B'
)AND c.customer_id not in(
    select o.customer_id from orders as o
    where o.product_name = 'C'
)order by c.customer_name;