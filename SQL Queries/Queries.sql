1) Leetcode 176. Second Highest Salary 
select max(salary) as SecondHighestSalary from Employee where salary not in (select max(salary) from Employee);

select max(salary) as SecondHighestSalary from Employee where salary<(select max(salary) from Employee);

2)
