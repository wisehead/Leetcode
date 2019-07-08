# Write your MySQL query statement below
select A.FirstName, A.LastName, B.City, B.State
from Person as A left outer join Address as B
on A.PersonId =  B.PersonId;
