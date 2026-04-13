select name from customers
where id not in (
    select DISTINCt customer_id from orders
);