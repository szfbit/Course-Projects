<!DOCTYPE>
<html>
<head>
<jsp:useBean id="account" type="beanClass.User" scope="session"/>
<title>Welcome!~<%=account.getUserName()%>~</title>
<link href="css/wrapper.css" rel="stylesheet" type="text/css" media="screen" />
<link href="css/userinfo.css" rel="stylesheet" type="text/css" media="screen" />
<link href="css/navigation.css" rel="stylesheet" type="text/css" media="screen" />
<script type="text/javascript" src="js/date.js"></script>


</head>
<%if(!session.getAttribute("login").equals("false")){%>
<body onload="yearClick(); monthClick(); dayClick();">
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
                            <a href="Logout">Log out</a>
                            <%}%>
			</nav>

			<div id="cartCheck">
				<button id="cartB" onclick="location.href='cart.do'">Cart</button>
				<button id="checkB" onclick="location.href='pay.do'">Check</button>
			</div>
		</div>

		<div id="menu">
			<ul class="menuClass">
				<li><a href="<%= request.getContextPath()%>/index">Homepage</a></li>
				<li><a href="<%= request.getContextPath()%>/Classification">Classification</a></li>
				<li><a href="<%= request.getContextPath()%>/Onsale">On Sale</a></li>
			</ul>
		</div>
 		
 		<div id="nav" class="navClass">
 			<a href="<%= request.getContextPath()%>/userInfo.jsp">User information</a><hr/>
 			<a href="<%= request.getContextPath()%>/purRecord.do">Purchase record</a><hr/>
 			<a href="<%= request.getContextPath()%>/revisePswd.jsp">Revise password</a><hr/>
 			<a href="fav.do">Favorite</a><hr/>
 			<a href="<%= request.getContextPath()%>/MyRemarkDisplay?email=<%=account.getEmail()%>">My remark</a><hr/>
 		</div>

 		<div id="userinfo">
                    <form id="reviseUsr" action="<%= request.getContextPath()%>/ReviseUserInfo" method="POST">
                        <input name="usrid" type="hidden" value="<%= account.getId()%>"/>
                        <input name="usremail" type="hidden" value="<%= account.getEmail()%>"/>
 			<table id="usertable">
 				<tr>
 					<td>Name</td>
                                        <td><input name="usrname" value="<%=account.getUserName()%>"/></td>
 					<td rowspan="4" class="imgCenter"><img id="level" src="images/levelImages/level<%=account.getLevel()%>.jpg"/></td>
 				</tr>

 				<tr>
 					<td>Gender</td>
 					<td>
 						<select name="gender">
 							<option value="1">Male</option>
 							<option value="0">Female</option>
 						</select>
 					</td>
 				</tr>

 				<tr>
 					<td>Date of birth</td>
 					<td>
 						<select name="year" id="year" onchange="yearChange()">
 							<option value="yyyy">yyyy</option>
 						</select>

 						<select name="month" id="month" onchange="monthChange()">
 							<option value="mm">mm</option>
 						</select>

 						<select name="day" id="day">
 							<option value="dd">dd</option>
 						</select>
 					</td>
 				</tr>
 				
 				<tr>
 					<td>E-mail</td>
 					<td><%= account.getEmail()%></td>
 				</tr>
	
 				<tr>
 					<td>Phone</td>
 					<td><input type="text" name="phone" value="<%= account.getPhone()%>"/></td>
 				</tr>

 				<tr>
 					<td>Loyalty point: </td>
 					<td><%= account.getPoint()%> pts</td>
 				</tr>

 				<tr>
 					<td></td><td></td>
 					<td>
                                            <button type="submit">save</button>
                                            <button type="reset">reset</button>
 					</td>
 				</tr>
 			</table>
                    </form>
 		</div>

		<div id="footer">
			<p>Author: WANG Yiji(52639040), ZOU Shaokun(52639296)</p>
			<p>All Rights Reserved</p>
		</div>

	</div>
</body>
<%}else{
    response.sendRedirect("login.jsp");
}%>
</html>