-- 1) Leetcode 176. Second Highest Salary 
select max(salary) as SecondHighestSalary from Employee where salary not in (select max(salary) from Employee);

select max(salary) as SecondHighestSalary from Employee where salary<(select max(salary) from Employee);


select ifnull(
    (select distinct salary from Employee order by salary desc limit 1 offset 1),
    null)
as SecondHighestSalary;

--------------------------------------------------------------------------------------------------------
--2) Leetcode 177. nth highest salary

CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
    declare nthSalary int;
    set N=N-1;
        # Write your MySQL query statement below.
    select ifnull((select distinct salary from Employee order by salary desc limit 1 offset N),null)
    into nthSalary;

    return nthSalary;
  
END;


CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
    set N = N - 1;
    RETURN (
        # Write your MySQL query statement below.
        select distinct salary from Employee order by salary desc limit N, 1
    );
END


--------------------------------------------------------------------------------------------------------
--3) Leetcode 184. Department wise highest salary

select D.name as Department,E.name as Employee,E.salary as Salary
from Employee E join Department D on E.departmentId=D.id
where E.salary in
    (
       select max(salary) from Employee E1 where E.departmentId=E1.departmentId
    )
;


select D.name as Department,E.name as Employee, E.salary as Salary
    from Employee as E join Department as D 
    on E.departmentId = D.id 
    and E.salary = (select max(salary) from Employee where departmentId=D.id)


    --this is best as this is subquery not correlated
# Write your MySQL query statement below
select D.name as Department,E.name as Employee,E.salary as Salary
from Employee E 
join Department D on E.departmentId=D.id
where (E.departmentId,E.salary) in 
    (
       select E1.departmentId,max(salary) 
       from Employee E1
       group by E1.departmentId
    )
;


--------------------------------------------------------------------------------------------------------
--4) Leetcode 185. Department Top Three Salaries

--Basic approach
# Write your MySQL query statement below
select 
    d.name as Department, 
    e.name as Employee, 
    e.salary as Salary
from 
    Employee e 
    join Department d 
    on e.departmentId = d.id
where (
    select count(distinct salary) 
    from Employee e2
    where 
        e2.departmentId = e.departmentId
        and e2.salary >= e.salary
)<=3;


--Pro level
select x.Department,x.Employee,x.Salary from
(select 
    d.name as Department,
    e.name as Employee,
    e.salary as Salary,
    dense_rank() over(partition by d.id order by salary desc) as rnk
from Employee e inner join Department d on e.departmentId = d.id) x
where x.rnk<4

--reference : https://www.youtube.com/watch?v=Ww71knvhQ-s

--------------------------------------------------------------------------------------------------------

--5) Leetcode 1045. Customers Who Bought All Products

select customer_id
from Customer
group by customer_id
having count(distinct product_key)= (select count(*) from Product)

--------------------------------------------------------------------------------------------------------
--6) Leetcode 570. Managers with at Least 5 Direct Reports

select name from Employee where id in(
select managerId from Employee
group by managerId
having count(*)>=5)

--------------------------------------------------------------------------------------------------------
--7) Leetcode 1934. Confirmation Rate   [Needs Revision]

select
    s.user_id,
    case
        when c.user_id is null then 0
        else round(sum(c.action='confirmed')/count(c.user_id),2)
    end as confirmation_rate
from 
    Signups s left join Confirmations c
    on s.user_id = c.user_id
group by 
    s.user_id

--------------------------------------------------------------------------------------------------------
--178. Rank Scores

select 
    score,
    dense_rank() over(order by score desc)  as "rank"
from 

--------------------------------------------------------------------------------------------------------
--626. Exchange Seats

SELECT 
    CASE 
        WHEN id = (SELECT MAX(id) FROM seat) AND id % 2 = 1
            THEN id 
        WHEN id % 2 = 1
            THEN id + 1
        ELSE id - 1
    END AS id,
    student
FROM seat
ORDER BY id


--------------------------------------------------------------------------------------------------------
--180. Consecutive Numbers

with t as (
    select num,lag(num,1) over() as lag1,lag(num,2) over() as lag2 from Logs)
select distinct num as ConsecutiveNums 
from t
where num=lag1 and lag1=lag2