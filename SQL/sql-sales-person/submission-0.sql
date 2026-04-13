select name from sales_person
where sales_id not in(
    select o.sales_id from orders as o
    left join company as c
    on o.com_id = c.com_id
    where c.name = 'CRIMSON'
)