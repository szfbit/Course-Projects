<!DOCTYPE>
<html>
<head>
<title>Welcome</title>
<link href="css/wrapper.css" rel="stylesheet" type="text/css" media="screen" />
<link href="css/navigation.css" rel="stylesheet" type="text/css" media="screen" />
<link href="css/revisepswd.css" rel="stylesheet" type="text/css" media="screen" />
<script type="text/javascript" src="js/revisepswd.js"></script>
</head>
<jsp:useBean id="account" type="beanClass.User" scope="session"/>
<body>
<%if(!session.getAttribute("login").equals("false")){%>    
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
                
 		<div id="revise">
                    <form id="pswd" action="<%= request.getContextPath()%>/RevisePswd">
                        <input name="email" type="hidden" value="<%=account.getEmail()%>"/>
 			<table>
 				<tr>
 					<td colspan="2" id="blank">
 						Password should not be blank!
 					</td>
 				</tr>
 				<tr>
 					<td colspan="2" id="wrong">
 						Password not match!
 					</td>
 				</tr>
 				<tr>
 					<td>Name</td>
 					<td><%= account.getUserName()%></td>
 				</tr>

 				<tr>
 					<td>new password</td>
 					<td><input name="newpswd" id="newP" type="password" value=""/></td>
 				</tr>

 				<tr>
 					<td>confirm password</td>
 					<td><input type="password" id="conP" value=""/></td>
 				</tr>
 			</table>
 			<div id="confirm_cancel">
 				<button id="con_sav" onclick="check();">Confirm</button>
 				<button>Reset</button>		
 			</div>	
                    </form>
 		</div>
 		
		<div id="footer">
			<p>Author: WANG Yiji(52639040), ZOU Shaokun(52639296)</p>
			<p>All Rights Reserved</p>
		</div>

	</div>
<%}else{
    response.sendRedirect("login.jsp");
}%>                                
</body>
</html>