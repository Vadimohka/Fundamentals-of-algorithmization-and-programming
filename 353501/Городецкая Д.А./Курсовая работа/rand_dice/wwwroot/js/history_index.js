function sortData() {
    var sortingOption = document.getElementById("sortingOption").value;
    var tableBody = document.querySelector("table tbody");
    var rows = Array.from(tableBody.rows);

    rows.sort(function (a, b) {
        var aValue, bValue;
        switch (sortingOption) {
            case "SortByDiceFaces":
                aValue = a.cells[0].textContent;
                bValue = b.cells[0].textContent;
                break;
            case "SortByDiceValue":
                aValue = parseInt(a.cells[1].textContent);
                bValue = parseInt(b.cells[1].textContent);
                break;
            case "SortByChance":
                aValue = parseFloat(a.cells[2].textContent);
                bValue = parseFloat(b.cells[2].textContent);
                break;
        }
        if (aValue < bValue) return -1;
        if (aValue > bValue) return 1;
        return 0;
    });

    rows.forEach(function (row) {
        tableBody.appendChild(row);
    });
}