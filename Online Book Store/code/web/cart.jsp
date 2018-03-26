<!DOCTYPE>
<html>
<head>
<title>Cart</title>
<link href="css/wrapper.css" rel="stylesheet" type="text/css" media="screen" />
<link href="css/cart/cart.css" rel="stylesheet" type="text/css" media="screen" />
<script type='text/javascript'>
    function normal(x)
    {
        var t=0;
        for(var ind=0;ind<=x-1;ind++)
        {
            var subid="sub"+ind;
            var pid="p"+ind;
            var qid="s"+ind;
            t+=Math.round(document.getElementById(pid).innerHTML*document.getElementById(qid).value*100)/100;;
            document.getElementById(subid).innerHTML=
                    Math.round(document.getElementById(pid).innerHTML*document.getElementById(qid).value*100)/100;
        }
        document.getElementById("total").innerHTML=Math.round(t*100)/100;
    }
    function changeSub(ind,bookid)
    {
        var extid="extra"+ind;
        var subid="sub"+ind;
        var pid="p"+ind;
        var qid="s"+ind;
        var newNum=document.getElementById(qid).value;
        var url="cart.do?id="+bookid+"&newNum="+newNum+"&action=update"+"&pre="+"<%=request.getParameter("pre")%>";
        document.getElementById(extid).innerHTML="<a href='"+url+"'>update</a>"
        document.getElementById(subid).innerHTML=
                Math.round(document.getElementById(pid).innerHTML*document.getElementById(qid).value*100)/100;
        var x=document.getElementById("num").innerHTML;
        var t=0;
        for(var ind=0;ind<=x-1;ind++)
        {
            var subd="sub"+ind;
            t+=document.getElementById(subd).innerHTML;
        }
        document.getElementById("total").innerHTML=Math.round(t*100)/100;        
    }

</script>
</head>
<jsp:useBean id="cart" type="beanClass.Cart" scope="session" />
<jsp:useBean id="account" type="beanClass.User" scope="session"/>
<body onload="normal(<%=cart.getCount()%>)">
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
        <div id="content">
            <span id="error" style='color: red'>
            <%String error=request.getParameter("error");
            if(error!=null){
                if(error.equals("c1")){%>
                    no item to update!
                <%}else if(error.equals("c2")){%>
                    no item to delete!
                <%}else if(error.equals("c3")){%>
                    duplicate addition!
                <%}else{%>
                    Other error!                            
                <%}}%>
            </span>            
            <div id="tableContainer">
                <table id="table">
                <thead>
                    <tr>
                        <td class="title">Title</td>
                        <td class="price">Price</td>
                        <td class="type">Type</td>
                        <td class="qty">Quantity</td>
                        <td class="subt">Subtotal</td>
                        <td class="del">Delete Item</td>
                    </tr>                    
                </thead>
                <tbody>
                    <%for(int i=0;i<=cart.getCount()-1;i++){%>                    
                        <tr>
                            <td class="title" title='<%= cart.getLists().get(i).getName()%>'>
                                <%= cart.getLists().get(i).getName()%>
                            </td>
                            <td class="price" id='p<%=i%>'>
                                <%= cart.getLists().get(i).getCurrent_price()%>
                            </td>
                            <td class="type">
                                <%= cart.getLists().get(i).getCat()%>
                            </td>
                            <td class="qty">
                                <input type="number" value="<%=cart.getNum().get(i)%>" id="s<%=i%>" min="0" max="100" step="1" onchange="changeSub(<%=i%>,'<%=cart.getLists().get(i).getId()%>')" />
                                <span id="extra<%=i%>">
                                    <%if(request.getParameter("suc")!=null&&cart.getLists().get(i).getId().equals(request.getParameter("suc"))){%>
                                    <b>saved!</b>
                                    <%}%>
                                </span>
                            </td>
                            <td class="subtotal"><span id="sub<%=i%>"></span></td>
                            <td class="del"><a href="cart.do?action=delete&id=<%=cart.getLists().get(i).getId()%>&pre=<%=request.getParameter("pre")%>">Delete</a></td>
                        </tr>
                    <%}%>
                    <tr>
                        <td colspan=6 class="sum"><span class="summ">Total: $<span id="total"></span></span></td>
                    </tr>
                    <tr>
                        <td colspan=6 class="sum"><span class="summ"><span id="num"><%=cart.getCount()%></span> Item(s)</span></td>
                    </tr>
                </tbody>
            </table>
            </div>
            <div id="box">
                <input type="button" value="Payment" class="button" onclick="location.href='pay.do'" />
                <input type="button" value="Continue" class="button" onclick="location.href='<%=request.getParameter("pre")%>'"/>
            </div>                    
        </div>
		<div id="footer">
			<p>Author: WANG Yiji(52639040), ZOU Shaokun(52639296)</p>
			<p>All Rights Reserved</p>
		</div>

	</div>
</body>
</html>