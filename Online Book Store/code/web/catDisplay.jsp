<!DOCTYPE>
<html>
<head>
<jsp:useBean id="b1" type="beanClass.Book" scope="request"/>
<jsp:useBean id="b2" type="beanClass.Book" scope="request"/>
<jsp:useBean id="b3" type="beanClass.Book" scope="request"/>
<jsp:useBean id="b4" type="beanClass.Book" scope="request"/>
<jsp:useBean id="b5" type="beanClass.Book" scope="request"/>
<title><%= b1.getCat()%></title>
<link href="css/wrapper.css" rel="stylesheet" type="text/css" media="screen" />
<link href="css/catDisplay.css" rel="stylesheet" type="text/css" media="screen" />
</head>

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
                            <a href="Logout">Log out</a>
                            <%}%>
			</nav>

			<div id="cartCheck">
				<button id="cartB">Cart</button>
				<button id="checkB">Check</button>
			</div>
		</div>

		<div id="menu">
			<ul class="menuClass">
				<li><a href="<%= request.getContextPath()%>/index">Homepage</a></li>
				<li><a href="<%= request.getContextPath()%>/Classification">Classification</a></li>
				<li><a href="#">On Sale</a></li>
			</ul>
		</div>
		<div id="cat">
	 		<table id="t1">
	 			<tr>
	 				<td colspan="3" class="catStyle"><%= b1.getCat()%></td>

	 			</tr>

	 			<tr>
	 				<td class="tdLR">
                                                <a href="<%= request.getContextPath()%>/bookInfoDisplay?bookID=<%=b1.getId()%>">
                                                        <img src="images/bookImages/<%= b1.getId()%>.jpg"/>
                                                </a>
                                        </td>

                                        <td class="tdLR">
                                                <a href="<%= request.getContextPath()%>/bookInfoDisplay?bookID=<%=b2.getId()%>">
                                                        <img src="images/bookImages/<%= b2.getId()%>.jpg"/>
                                                </a>
                                        </td>

                                        <td class="tdLR">
                                                <a href="<%= request.getContextPath()%>/bookInfoDisplay?bookID=<%=b3.getId()%>">
                                                        <img src="images/bookImages/<%= b3.getId()%>.jpg"/>
                                                </a>
                                        </td>
	 			</tr>

	 			<tr>
	 				<td class="tdLRB">
                                                <a href="<%= request.getContextPath()%>/bookInfoDisplay?bookID=<%=b1.getId()%>">
                                                        <%=b1.getName()%>
                                                </a>
                                        </td>
                                        <td class="tdLRB">
                                                <a href="<%= request.getContextPath()%>/bookInfoDisplay?bookID=<%=b2.getId()%>">
                                                        <%=b2.getName()%>
                                                </a>
                                        </td>
                                        <td class="tdLRB">
                                                <a href="<%= request.getContextPath()%>/bookInfoDisplay?bookID=<%=b3.getId()%>">
                                                        <%=b3.getName()%>
                                                </a>
                                        </td>
	 			</tr>
	 		</table>
	 		<table id="t2">
	 			<tr>
	 				<td class="tdLR">
                                                <a href="<%= request.getContextPath()%>/bookInfoDisplay?bookID=<%=b4.getId()%>">
                                                        <img src="images/bookImages/<%= b4.getId()%>.jpg"/>
                                                </a>
                                        </td>

                                        <td class="tdLR">
                                                <a href="<%= request.getContextPath()%>/bookInfoDisplay?bookID=<%=b5.getId()%>">
                                                        <img src="images/bookImages/<%= b5.getId()%>.jpg"/>
                                                </a>
                                        </td>
	 			</tr>

	 			<tr>
	 				<td class="tdLRB">
                                                <a href="<%= request.getContextPath()%>/bookInfoDisplay?bookID=<%=b4.getId()%>">
                                                        <%=b4.getName()%>
                                                </a>
                                        </td>
                                        <td class="tdLRB">
                                                <a href="<%= request.getContextPath()%>/bookInfoDisplay?bookID=<%=b5.getId()%>">
                                                        <%=b5.getName()%>
                                                </a>
                                        </td>
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