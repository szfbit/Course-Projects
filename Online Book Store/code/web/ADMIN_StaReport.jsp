<!DOCTYPE>
<html>
<head>
<title>ADMIN-Users</title>
<link href="css/wrapper.css" rel="stylesheet" type="text/css" media="screen" />
<link href="css/ADMIN_StaReport.css" rel="stylesheet" type="text/css" media="screen" />
<script type="text/javascript" src="js/ADMIN_ManageUser.js"></script>
</head>
<jsp:useBean id="rpt" type="beanClass.StaReport" scope="session"/>
<jsp:useBean id="account" type="beanClass.User" scope="session"/>
<body>
	<div id="wrapper">
		<div id="upper">
			<div id="logoBlock">
				<img id="logo" src="images/logo.png"/>
			</div>

			<div id="search">
                            <form action="<%= request.getContextPath()%>/Search" method="POST">
				<img id="searchImage" src="images/search.png"/>
                                <select id="selectS" name="tp">
                                    <option value="Name">Name</option>
                                    <option value="Author">Author</option>
                                    <option value="BookID">BookID</option>
                                    <option value="Publisher">Publisher</option>                               
                                </select>
                                <input name="keyWd" id="searchText" type="text" placeholder="Search" />
				<button id="searchButton" type="submit">Search</button> 
                            </form>
			</div>

			<nav id="loginReg">
				<%if(session.getAttribute("login").equals("false")){ %>
				<a href="login.jsp">log in</a>
				<a href="register.jsp">Register</a>
                            <%}else{%>
                            <a href="userInfo.jsp"><jsp:getProperty name="account" property="userName" /></a>
                                    <a href="#">Log out</a>
                            <%}%>
			</nav>

		</div>

		<div id="menu">
			<ul class="menuClass">
                                <li><a href="<%= request.getContextPath()%>/ADMIN_allbooks">Books</a></li>
				<li><a href="<%= request.getContextPath()%>/ADMIN_allusers">Users</a></li>
				<li><a href="<%= request.getContextPath()%>/ADMIN_StaReport">Statistics</a></li>
				<li><a href="refund.do">Requests</a></li>
			</ul>
		</div>
 		
 		<div id="tb">
 			<table id="usersT">
                            <tr>
 				<td>Book Number</td>
                                <td><%=rpt.getBook()%></td>
                            </tr>
                            <tr>
 				<td>Remark Number</td>
                                <td><%=rpt.getRemark()%></td>
                            </tr>
                            <tr>
 				<td>User Number/Banned User Number</td>
                                <td><%=rpt.getUser()%>/<%=rpt.getBannedUser()%></td>
                            </tr>
                            <tr>
 				<td>Sales Volume</td>
                                <td><%=rpt.getSalesVolume()%></td>
                            </tr>
                            <tr>
                                <td>Total Income</td>
                                <td><%=rpt.getIncome()%></td>
                            </tr>
                            <tr>
 				<td>Refund Number</td>
                                <td><%=rpt.getRefund()%></td>
                            </tr>
 			</table>
 		</div>

		<div id="footer">
			<p>Author: WANG Yiji(52639040), ZOU Shaokun(52639296)</p>
			<p>All Rights Reserved</p>
		</div>

	</div>
</body>
</html>