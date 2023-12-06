--Nuevo procedimiento de registros duplicados.
--Paso 1
CREATE TABLE inventory_raw_item_temp (LIKE inventory_raw_item INCLUDING INDEXES);
--Paso 2
INSERT INTO inventory_raw_item_temp(
    id,
    "prefix",
    subfix,
    "name",
    newpos_name,
    "group",
    group_name,
    wh_group,
    pg_prefix,
    pg_subfix,
    count_period,
    wh_count_period,
    user_count_period,
    package_unit,
    sub_unit,
    usage_unit,
    sub_units_per_case,
    usage_units_per_case,
    price_per_package,
    price_package_new,
    green_point_price,
    unit_price,
    principal_vendor,
    secondary_vendor,
    is_waste_allowed,
    is_promo_allowed,
    is_recipe_allowed,
    is_yield_calculation_allowed,
    yield,
    yield_dev,
    minimun_days,
    minimun_stock,
    warehouse1,
    sequence1,
    wh_sequence1,
    user_sequence1,
    status,
    effective_date,
    update_user,
    update_date)
SELECT
    DISTINCT ON (prefix, subfix) 
    id,
    "prefix",
    subfix,
    "name",
    newpos_name,
   "group",
    group_name,
    wh_group,
    pg_prefix,
    pg_subfix,
    count_period,
    wh_count_period,
    user_count_period,
    package_unit,
    sub_unit,
    usage_unit,
    sub_units_per_case,
    usage_units_per_case,
    price_per_package,
    price_package_new,
    green_point_price,
    unit_price,
    principal_vendor,
    secondary_vendor,
    is_waste_allowed,
    is_promo_allowed,
    is_recipe_allowed,
    is_yield_calculation_allowed,
    yield,
    yield_dev,
    minimun_days,
    minimun_stock,
    warehouse1,
    sequence1,
    wh_sequence1,
    user_sequence1,
    status,
    effective_date,
    update_user,
    update_date
	FROM inventory_raw_item;
-- Paso 3
DELETE FROM inventory_raw_item;
--	Paso 4 
INSERT INTO inventory_raw_item SELECT * FROM inventory_raw_item_temp;
--	Paso 5
DROP TABLE inventory_raw_item_temp;