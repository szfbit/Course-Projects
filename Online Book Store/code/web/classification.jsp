<!DOCTYPE>
<html>
<head>
<title>Classification</title>
<link href="css/wrapper.css" rel="stylesheet" type="text/css" media="screen" />
<link href="css/classification.css" rel="stylesheet" type="text/css" media="screen" />
</head>
<jsp:useBean id="c1f" type="beanClass.Book" scope="request"/>
<jsp:useBean id="c1s" type="beanClass.Book" scope="request"/>
<jsp:useBean id="c2f" type="beanClass.Book" scope="request"/>
<jsp:useBean id="c2s" type="beanClass.Book" scope="request"/>
<jsp:useBean id="c3f" type="beanClass.Book" scope="request"/>
<jsp:useBean id="c3s" type="beanClass.Book" scope="request"/>
<jsp:useBean id="c4f" type="beanClass.Book" scope="request"/>
<jsp:useBean id="c4s" type="beanClass.Book" scope="request"/>
<jsp:useBean id="c5f" type="beanClass.Book" scope="request"/>
<jsp:useBean id="c5s" type="beanClass.Book" scope="request"/>
<jsp:useBean id="c6f" type="beanClass.Book" scope="request"/>
<jsp:useBean id="c6s" type="beanClass.Book" scope="request"/>
<jsp:useBean id="c7f" type="beanClass.Book" scope="request"/>
<jsp:useBean id="c7s" type="beanClass.Book" scope="request"/>
<jsp:useBean id="c8f" type="beanClass.Book" scope="request"/>
<jsp:useBean id="c8s" type="beanClass.Book" scope="request"/>
<jsp:useBean id="c9f" type="beanClass.Book" scope="request"/>
<jsp:useBean id="c9s" type="beanClass.Book" scope="request"/>
<jsp:useBean id="c10f" type="beanClass.Book" scope="request"/>
<jsp:useBean id="c10s" type="beanClass.Book" scope="request"/>
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
		<div id="tbB">
			<!-- Arts & Photography -->
	 		<table>
	 			<tr>
                    <td colspan="2" class="catStyle">Arts & Photography</td>
	 			</tr>

	 			<tr>
                    <td class="tdLR"><a href="<%= request.getContextPath()%>/bookInfoDisplay?bookID=<%=c1f.getId()%>"><img src="images/bookImages/<%=c1f.getId()%>.jpg"/></a></td>
                    <td class="tdLR"><a href="<%= request.getContextPath()%>/bookInfoDisplay?bookID=<%=c1s.getId()%>"><img src="images/bookImages/<%=c1s.getId()%>.jpg"/></a></td>

	 			</tr>

	 			<tr>
	 				<td class="tdLRB"><a href="<%= request.getContextPath()%>/bookInfoDisplay?bookID=<%=c1f.getId()%>"><%=c1f.getName()%></a></td>
	 				<td class="tdLRB"><a href="<%= request.getContextPath()%>/bookInfoDisplay?bookID=<%=c1s.getId()%>"><%=c1s.getName()%></a></td>

	 			</tr>

	 			<tr>
	 				<td colspan="2" class="btn"><button onclick="javascript:location.href='<%= request.getContextPath()%>/CatDisplay?catType=Arts %26 Photography'">more</button></td>

	 			</tr>
	 		</table>
 		
 			<!-- Business & Money -->
	 		<table>
	 			<tr>

	 				<td colspan="2" class="catStyle">Business & Money</td>
	 			</tr>

	 			<tr>
	 				<td class="tdLR"><a href="<%= request.getContextPath()%>/bookInfoDisplay?bookID=<%=c2f.getId()%>"><img src="images/bookImages/<%=c2f.getId()%>.jpg"/></a></td>
	 				<td class="tdLR"><a href="<%= request.getContextPath()%>/bookInfoDisplay?bookID=<%=c2s.getId()%>"><img src="images/bookImages/<%=c2s.getId()%>.jpg"/></a></td>
	 			</tr>

	 			<tr>

	 				<td class="tdLRB"><a href="<%= request.getContextPath()%>/bookInfoDisplay?bookID=<%=c2f.getId()%>"><%=c2f.getName()%></a></td>
	 				<td class="tdLRB"><a href="<%= request.getContextPath()%>/bookInfoDisplay?bookID=<%=c2s.getId()%>"><%=c2s.getName()%></a></td>
	 			</tr>

	 			<tr>

	 				<td colspan="2"  class="btn"><button onclick="javascript:location.href='<%= request.getContextPath()%>/CatDisplay?catType=Business %26 Money'">more</button></td>
	 			</tr>
	 		</table>

	 		<!-- Children's Books -->
	 		<table>
	 			<tr>

	 				<td colspan="2" class="catStyle">Children's Books</td>
	 			</tr>

	 			<tr>
	 				<td class="tdLR"><a href="<%= request.getContextPath()%>/bookInfoDisplay?bookID=<%=c3f.getId()%>"><img src="images/bookImages/<%=c3f.getId()%>.jpg"/></a></td>
	 				<td class="tdLR"><a href="<%= request.getContextPath()%>/bookInfoDisplay?bookID=<%=c3s.getId()%>"><img src="images/bookImages/<%=c3s.getId()%>.jpg"/></a></td>
	 			</tr>

	 			<tr>

	 				<td class="tdLRB"><a href="<%= request.getContextPath()%>/bookInfoDisplay?bookID=<%=c3f.getId()%>"><%=c3f.getName()%></a></td>
	 				<td class="tdLRB"><a href="<%= request.getContextPath()%>/bookInfoDisplay?bookID=<%=c3s.getId()%>"><%=c3s.getName()%></a></td>
	 			</tr>

	 			<tr>

	 				<td colspan="2"  class="btn"><button onclick="javascript:location.href='<%= request.getContextPath()%>/CatDisplay?catType=Children\'s Books'">more</button></td>
	 			</tr>
	 		</table>


	 		<!-- Computer & Technology Books -->
	 		<table>
	 			<tr>

	 				<td colspan="2" class="catStyle">Computer & Technology Books</td>
	 			</tr>

	 			<tr>
	 				<td class="tdLR"><a href="<%= request.getContextPath()%>/bookInfoDisplay?bookID=<%=c4f.getId()%>"><img src="images/bookImages/<%=c4f.getId()%>.jpg"/></a></td>
	 				<td class="tdLR"><a href="<%= request.getContextPath()%>/bookInfoDisplay?bookID=<%=c4s.getId()%>"><img src="images/bookImages/<%=c4s.getId()%>.jpg"/></a></td>
	 			</tr>

	 			<tr>

	 				<td class="tdLRB"><a href="<%= request.getContextPath()%>/bookInfoDisplay?bookID=<%=c4f.getId()%>"><%=c4f.getName()%></a></td>
	 				<td class="tdLRB"><a href="<%= request.getContextPath()%>/bookInfoDisplay?bookID=<%=c4s.getId()%>"><%=c4s.getName()%></a></td>
	 			</tr>

	 			<tr>

	 				<td colspan="2"  class="btn"><button onclick="javascript:location.href='<%= request.getContextPath()%>/CatDisplay?catType=Computer %26 Technology Books'">more</button></td>
	 			</tr>
	 		</table>

	 		<!-- Cookbooks, Food & Wine -->
	 		<table>
	 			<tr>

	 				<td colspan="2" class="catStyle">Cookbooks, Food & Wine</td>
	 			</tr>

	 			<tr>
	 				<td class="tdLR"><a href="<%= request.getContextPath()%>/bookInfoDisplay?bookID=<%=c5f.getId()%>"><img src="images/bookImages/<%=c5f.getId()%>.jpg"/></a></td>
	 				<td class="tdLR"><a href="<%= request.getContextPath()%>/bookInfoDisplay?bookID=<%=c5s.getId()%>"><img src="images/bookImages/<%=c5s.getId()%>.jpg"/></a></td>
	 			</tr>

	 			<tr>

	 				<td class="tdLRB"><a href="<%= request.getContextPath()%>/bookInfoDisplay?bookID=<%=c5f.getId()%>"><%=c5f.getName()%></a></td>
	 				<td class="tdLRB"><a href="<%= request.getContextPath()%>/bookInfoDisplay?bookID=<%=c5s.getId()%>"><%=c5s.getName()%></a></td>
	 			</tr>

	 			<tr>

	 				<td colspan="2"  class="btn"><button onclick="javascript:location.href='<%= request.getContextPath()%>/CatDisplay?catType=Cookbooks, Food %26 Wine'">more</button></td>
	 			</tr>
	 		</table>

	 		<!-- Travel -->
	 		<table>
	 			<tr>

	 				<td colspan="2" class="catStyle">Travel</td>
	 			</tr>

	 			<tr>
	 				<td class="tdLR"><a href="<%= request.getContextPath()%>/bookInfoDisplay?bookID=<%=c6f.getId()%>"><img src="images/bookImages/<%=c6f.getId()%>.jpg"/></a></td>
	 				<td class="tdLR"><a href="<%= request.getContextPath()%>/bookInfoDisplay?bookID=<%=c6s.getId()%>"><img src="images/bookImages/<%=c6s.getId()%>.jpg"/></a></td>
	 			</tr>

	 			<tr>

	 				<td class="tdLRB"><a href="<%= request.getContextPath()%>/bookInfoDisplay?bookID=<%=c6f.getId()%>"><%=c6f.getName()%></a></td>
	 				<td class="tdLRB"><a href="<%= request.getContextPath()%>/bookInfoDisplay?bookID=<%=c6s.getId()%>"><%=c6s.getName()%></a></td>
	 			</tr>

	 			<tr>

	 				<td colspan="2"  class="btn"><button onclick="javascript:location.href='<%= request.getContextPath()%>/CatDisplay?catType=Travel'">more</button></td>
	 			</tr>
	 		</table>

	 		<!-- Sports & Outdoors -->
	 		<table>
	 			<tr>

	 				<td colspan="2" class="catStyle">Sports & Outdoors</td>
	 			</tr>

	 			<tr>
	 				<td class="tdLR"><a href="<%= request.getContextPath()%>/bookInfoDisplay?bookID=<%=c7f.getId()%>"><img src="images/bookImages/<%=c7f.getId()%>.jpg"/></a></td>
	 				<td class="tdLR"><a href="<%= request.getContextPath()%>/bookInfoDisplay?bookID=<%=c7s.getId()%>"><img src="images/bookImages/<%=c7s.getId()%>.jpg"/></a></td>
	 			</tr>

	 			<tr>

	 				<td class="tdLRB"><a href="<%= request.getContextPath()%>/bookInfoDisplay?bookID=<%=c7f.getId()%>"><%=c7f.getName()%></a></td>
	 				<td class="tdLRB"><a href="<%= request.getContextPath()%>/bookInfoDisplay?bookID=<%=c7s.getId()%>"><%=c7s.getName()%></a></td>
	 			</tr>

	 			<tr>

	 				<td colspan="2"  class="btn"><button onclick="javascript:location.href='<%= request.getContextPath()%>/CatDisplay?catType=Sports %26 Outdoors'">more</button></td>
	 			</tr>
	 		</table>

	 		<!-- Science Fiction & Fantasy -->
	 		<table>
	 			<tr>

	 				<td colspan="2" class="catStyle">Science Fiction & Fantasy</td>
	 			</tr>

	 			<tr>
	 				<td class="tdLR"><a href="<%= request.getContextPath()%>/bookInfoDisplay?bookID=<%=c8f.getId()%>"><img src="images/bookImages/<%=c8f.getId()%>.jpg"/></a></td>
	 				<td class="tdLR"><a href="<%= request.getContextPath()%>/bookInfoDisplay?bookID=<%=c8s.getId()%>"><img src="images/bookImages/<%=c8s.getId()%>.jpg"/></a></td>
	 			</tr>

	 			<tr>

	 				<td class="tdLRB"><a href="<%= request.getContextPath()%>/bookInfoDisplay?bookID=<%=c8f.getId()%>"><%=c8f.getName()%></a></td>
	 				<td class="tdLRB"><a href="<%= request.getContextPath()%>/bookInfoDisplay?bookID=<%=c8s.getId()%>"><%=c8s.getName()%></a></td>
	 			</tr>

	 			<tr>

	 				<td colspan="2"  class="btn"><button onclick="javascript:location.href='<%= request.getContextPath()%>/CatDisplay?catType=Science Fiction %26 Fantasy'">more</button></td>
	 			</tr>
	 		</table>

	 		<!-- Romance -->
	 		<table>
	 			<tr>

	 				<td colspan="2" class="catStyle">Romance</td>
	 			</tr>

	 			<tr>
	 				<td class="tdLR"><a href="<%= request.getContextPath()%>/bookInfoDisplay?bookID=<%=c9f.getId()%>"><img src="images/bookImages/<%=c9f.getId()%>.jpg"/></a></td>
	 				<td class="tdLR"><a href="<%= request.getContextPath()%>/bookInfoDisplay?bookID=<%=c9s.getId()%>"><img src="images/bookImages/<%=c9s.getId()%>.jpg"/></a></td>
	 			</tr>

	 			<tr>

	 				<td class="tdLRB"><a href="<%= request.getContextPath()%>/bookInfoDisplay?bookID=<%=c9f.getId()%>"><%=c9f.getName()%></a></td>
	 				<td class="tdLRB"><a href="<%= request.getContextPath()%>/bookInfoDisplay?bookID=<%=c9s.getId()%>"><%=c9s.getName()%></a></td>
	 			</tr>

	 			<tr>

	 				<td colspan="2"  class="btn"><button onclick="javascript:location.href='<%= request.getContextPath()%>/CatDisplay?catType=Romance'">more</button></td>
	 			</tr>
	 		</table>

	 		<!-- Politics & Social Sciences -->
	 		<table>
	 			<tr>

	 				<td colspan="2" class="catStyle">Politics & Social Sciences</td>
	 			</tr>

	 			<tr>
	 				<td class="tdLR"><a href="<%= request.getContextPath()%>/bookInfoDisplay?bookID=<%=c10f.getId()%>"><img src="images/bookImages/<%=c10f.getId()%>.jpg"/></a></td>
	 				<td class="tdLR"><a href="<%= request.getContextPath()%>/bookInfoDisplay?bookID=<%=c10s.getId()%>"><img src="images/bookImages/<%=c10s.getId()%>.jpg"/></a></td>
	 			</tr>

	 			<tr>

	 				<td class="tdLRB"><a href="<%= request.getContextPath()%>/bookInfoDisplay?bookID=<%=c10f.getId()%>"><%=c10f.getName()%></a></td>
	 				<td class="tdLRB"><a href="<%= request.getContextPath()%>/bookInfoDisplay?bookID=<%=c10s.getId()%>"><%=c10s.getName()%></a></td>
	 			</tr>

	 			<tr>

	 				<td colspan="2"  class="btn"><button onclick="javascript:location.href='<%= request.getContextPath()%>/CatDisplay?catType=Politics %26 Social Sciences'">more</button></td>
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